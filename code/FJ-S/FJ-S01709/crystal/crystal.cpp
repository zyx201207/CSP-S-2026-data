#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int n;
ll a[500005];
ll m;
ll f[500005];
int b[500005],e[500005];
bool i=false;

int check(int num,int b,int e){
	int l=b,r=e,mid;
	while(l<=r){
		mid=(l+r)/2;
		if(f[mid]<num){
			l=mid;
		}
		else if(f[mid]>num){
			r=mid;
		}
		if((f[mid]<num && f[mid+1]>num) || (f[mid]>num && f[mid-1]<num))
			break;
		if(f[mid]==num) break;
	}
	if(i==false) return mid;
	else if(i==true) return mid-b+1;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	bool flag=true;//等差数列判断 
	
	cin>>n>>m;
	if(n==1){
		cin>>a[1];
		cout<<1;
		return 0;
	}//n==1特判 
	
	cin>>a[1];
	cin>>a[2];
	for(int i=3;i<=n;i++){
		cin>>a[i];
		int k1=a[i-1]-a[i-2];
		int k2=a[i]-a[i-1];
		if(k1!=k2){
			flag=false;
		}
	}
	
	if(flag==true){
		int k=a[2]-a[1];
		if(k>m){
			cout<<1;
			return 0;
		}
		f[2]=k;
		for(int i=3;i<=n;i++){
			f[i]=f[i-1]+k*(i-1);
		}
		if(m>=f[n]){
			cout<<n;
			return 0;
		}
		else{
			int cnt=check(m,2,n);
			cout<<cnt;
			return 0;
		}
	}//对于性质AB的特别处理 
	
	 else{
	 	sort(a+1,a+n+1); 
	 	int cnt=2;
	 	int rec=1;
		while(true){
			if(cnt>n) {
				if(e[rec]==0) e[rec]=n;
				break;	
			}
			if(a[cnt]-a[cnt-1]>m && a[cnt+1]-a[cnt]<=m){
				if(b[rec]==0){
				cnt++;
				b[rec]=cnt-1;
				i=true;
				continue;
			}
				else{
					e[rec]=cnt-1,rec++;
				}
			}
			if(a[cnt]-a[cnt-1]<=m){
				if(cnt>b[rec]){
					f[cnt]=f[cnt-1]+(a[cnt]-a[cnt-1])*(cnt-b[rec]-1);
				}
			}
			cnt++;
		}
		int maxn=-1;
		for(int i=1;i<=rec;i++){
			int cnt=0;
			if(m>=f[e[rec]]){
				cnt=e[rec]-b[rec];
				cout<<cnt<<endl;
				maxn=max(maxn,cnt);
				continue;
			}
			cnt=check(m,b[i],e[i]);
			while(1){
				if(f[cnt]<f[cnt+1]) break;
				cnt++;
			}
			if(cnt>maxn) maxn=cnt;
		}
		cout<<maxn;
	}
	return 0;
} 
//awa
