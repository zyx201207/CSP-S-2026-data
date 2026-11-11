#include<bits/stdc++.h>
using namespace std;
int a[500005],d[500005],c[500005]={0},b[500005]={0};
int ans=0;
int dfs(int n,int m,int t){
	if(m<0){
		return 0;
	}
	sort(b,b+n);
	for(int i=0;i<n;i++){
		cout<<b[i]<<' ';
	}
	cout<<endl ;
	memset(c,0,sizeof c);
	
	int cnt=1;
	int num=0;
	for(int i=1;i<n;i++){
		if(a[i]==a[i-1]){
			cnt++;
		}
		else {
			c[num]=cnt;
			num++;
			cnt=1;
		}
	}
	
	cnt=*max_element(c,c+num);
	d[t]=cnt;
	//cout<<cnt<<' ';
	//cout<<cnt<<' ';
	for(int i=0;i<n;i++){
		b[i]++;
		//cout<<cnt<<' '<<b[i]<<"    ";
		m--;
		cnt=dfs(n,m--,t++);
		if(ans<cnt){
			ans=cnt;
		}
		//cout<<cnt<<' '<<b[i]<<endl;
		b[i]--;
	}
	
	return ans;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	if(m==1){
		cout<<1;
		return 0;
	}
	bool ok=0;
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				if(abs(a[i]-a[j])<10){
					ok=1;
				}
			}
		}
		if(!ok){
			cout<<2;
			return 0;
		}
		
		ok=1;
		for(int i=0;i<n-1;i++){
			if(a[i]!=a[i+1]){
				ok=0;
			}
		}	
		if(ok){
			cout<<1;
			return 0;
		}
		ok=1;
		for(int i=0;i<n-1;i++){
			if(a[i]!=a[i+1]-1){
				ok=0;
			}
		}
		if(ok){
			cout<<m;
			return 0;
		}
	ok=1;
	int d=a[1]-a[0];
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(a[j]-a[i]!=d){
				ok=0;
				break;
			}
			break ;
		}
	}
	if(ok){
		cout<<m/d;
		return 0;
	}
//	while(m--){
//		memset(c,0,sizeof c);
//		sort(a,a+n);
//		int cnt=1;
//		int num=0;
//		for(int i=1;i<n;i++){
//			if(a[i]==a[i-1]){
//				cnt++;
//			}
//			else {
//				c[num]=cnt;
//				num++;
//				cnt=0;
//			}
//				
//		}
//		int tmp,tmp1;
//		int cnt1=c[0];
//		for(int i=1;i<num;i++){
//			if(cnt1<c[i]){
//				cnt1=c[i];
//				tmp=i;
//			}
//		}
//		int ans=a[tmp];
//		for(int i=0;i<n;i++){
//			if(a[tmp]-a[i]<a[tmp]-ans){
//				ans=a[i];
//				tmp1=i;
//			} 
//		}
//		a[tmp1]++;
//	}
//		memset(c,0,sizeof c);
//		sort(a,a+n);
//		int cnt=1;
//		int num=0;
//		for(int i=1;i<n;i++){
//			if(a[i]==a[i-1]){
//				cnt++;
//			}
//			else {
//				c[num]=cnt;
//				num++;
//				cnt=0;
//			}
//				
//		}
//		int tmp;
//		int cnt1=c[0];
//		for(int i=1;i<num;i++){
//			if(cnt1<c[i]){
//				cnt1=c[i];
//				tmp=i;
//			}
//		}
//		cout<<cnt1;
	int num= dfs(n,m,0);
	int z=0;
	cout<<ans;
	return 0;
} 
