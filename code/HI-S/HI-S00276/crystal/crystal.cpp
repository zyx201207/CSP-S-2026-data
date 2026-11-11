#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
long long a[500005],li[500005];
bool tui=0;int l;
int dfs(){
	if(li[l]<=m){
		if(tui){
			cout<<l;
		}else{
			l+=1;
			return dfs();
		}
	}else{
		tui=1;l-=1;
		return dfs();
	}
	return 0;
}
void reding(){
	int cnt=0;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
	}
	a[0]=0;
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++){
		li[i]=(a[i]-a[i-1])*(i-1)+li[i-1];
	}
	int msl=n/2+(n%2==1);
	l=msl;
	dfs();
}
		



//namespace a_plan{
//	//int a[5005],li[5005];
//	bool tui=0;
//	int l;
//	int dfs(){
//		if(a[l]*(l-1)-li[l-1]<=m){
//			if(tui){
//				cout<<l;
//			}else{
//				l++;
//				return dfs();
//			}
//		}else{
//			tui=1;
//			l--;
//			return dfs();
//		}
//		return 0;
//	}
//	void reding(){
//		int cnt=0;
//		for(int i=1;i<=n;i++) {
//			cin>>a[i];
//		}
//		sort(a+1,a+1+n);
//		for(int i=1;i<=n;i++){
//			//cout<<a[i]<<' ';
//			li[i]=li[i-1]+a[i];
//		}
//		int msl=n/2+(n%2==1);
//		l=msl;cout<<l;
//		dfs();
//		cout<<l;
//	}
//}

int main(){
	freopen("crystal.in","r",stdin); 
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	if(m==0){
		for(int i=1;i<=n;i++) cin>>a[i];
		int ans=-1;
		sort(a+1,a+1+n);
		for(int i=1;i<=n;i++){
			int cnt=1;
			while(a[i+1]==a[i]){
				cnt++;
				i++;
			}
			ans=max(cnt,ans);
		}
		cout<<ans;
		return 0;
	}else{
		reding();
	}
	return 0;
} 


