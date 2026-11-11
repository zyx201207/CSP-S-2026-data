#include<iostream>
#include<cstdio>
using namespace std;
int q;
int n;
long long d;
long long a[2000006],lcnt[2000006],rcnt[2000006],lsum[2][2000006],rsum[2][2000006];//0 left,1 ritht
int l[2000006],r[2000006];
int sum[2000006],top;
void slove(){
	scanf("%d %lld",&n,&d);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		lcnt[i]=1;
		rcnt[i]=1;
	}
	for(int i=1;i<=n;i++){
		int L=0,R=i;
		while(L+1<R){
			int mid=(L+R)/2;
			if(a[mid]+d>=a[i])R=mid;
			else L=mid;
		}
		l[i]=R;
		L=i,R=n+1;
		while(L+1<R){
			int mid=(L+R)/2;
			if(a[mid]-d<=a[i])L=mid;
			else R=mid;
		}
		r[i]=L;
	}
	int cnt=0,L=1,R=0;
	for(int i=1;i<=n;i++){
		while(R+1<l[i+1]&&R+1<i){
			R++;
			cnt=cnt+lcnt[R];
		}
		while(L<l[i]){
			cnt=cnt-lcnt[L];
			L++;
		}
		lcnt[i]+=cnt; 
		lsum[0][i]=L;
		lsum[1][i]=R;
	}
	for(int i=1;i<=n;i++){
		lcnt[i]+=lcnt[i-1];
	} 
	cnt=0;
	L=n+1;
	R=n;
	for(int i=n;i>=1;i--){
		while(L-1>r[i-1]&&L-1>i){
			L--;
			cnt=cnt+rcnt[L];
		}
		while(R>r[i]){
			cnt=cnt-rcnt[R];
			R--;
		}
		rcnt[i]+=cnt;
		rsum[0][i]=L;
		rsum[1][i]=R;
	}
	for(int i=n;i>=1;i--){
		rcnt[i]+=rcnt[i+1];
	}
	long long ans=0;
	top=0;
	for(int i=2;i+1<n;i++){
		if((lcnt[lsum[0][i+2]-1]-lcnt[lsum[0][i+1]-1])<=0||lsum[0][i+1]>i-1)continue;
		if((rcnt[rsum[1][i-1]+1]-rcnt[rsum[1][i]+1])<=0||rsum[0][i]<i+2)continue;
		top++;
		sum[top]=i;
//		cout<<i<<'a'<<endl;
//		ans=ans+(lcnt[lsum[0][i+2]-1]-lcnt[lsum[0][i+1]-1])*(rcnt[rsum[1][i-1]+1]-rcnt[rsum[1][i]+1]);
	}
	for(int j=1;j<=top;j++){
		int i=sum[j];
		long long L,R;
		if(j>1&&sum[j-1]>lsum[0][i+1]&&sum[j-1]+1<lsum[0][i+1]-1){
			L=lcnt[lsum[0][i+2]-1]-lcnt[sum[j-1]+1-1];
		}else L=lcnt[lsum[0][i+2]-1]-lcnt[lsum[0][i+1]-1];
		if(j<top&&sum[j+1]>rsum[1][i-1]+1&&sum[j+1]+1<rsum[1][i]){
			R=rcnt[rsum[1][i-1]+1]-rcnt[sum[j+1]+1];
		}else R=rcnt[rsum[1][i-1]+1]-rcnt[rsum[1][i]+1];
		ans=ans+L*R;
//		cout<<i<<'b'<<endl;
//		cout<<L<<' '<<R<<endl;
	}
	printf("%lld\n",ans);
	/*
	for(int i=1;i<=n;i++){
		cout<<lcnt[i]-lcnt[i-1]<<' ';
	}
	cout<<endl;
	for(int i=1;i<=n;i++){
		cout<<rcnt[i]-rcnt[i+1]<<' ';
	}
	cout<<endl;
	for(int i=1;i<=n;i++){
		cout<<lsum[0][i]<<'l'<<lsum[1][i]<<endl;
	}
	for(int i=1;i<=n;i++){
		cout<<rsum[0][i]<<'r'<<rsum[1][i]<<endl;
	}
	for(int i=1;i<=n;i++){
		cout<<l[i]<<','<<r[i]<<endl;
	}
//	*/
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c;
	scanf("%d %d",&c,&q);
	for(int asdf=1;asdf<=q;asdf++){
		slove();
	}	
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

0 1
10 3
0 1 3 5 6 8 10 12 13 16
*/
