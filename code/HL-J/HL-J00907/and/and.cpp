#include<bits/stdc++.h>
using namespace std;
int a[1000000];
string b[1000000];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	int n,m;cin>>n>>m;
	int maxn=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}
	if(m<=2){
		cout<<maxn;
		return 0;
	}
	string k;
	if(m==n){
//		for(int i=1;i<=n;i++){
//			while(a[i]>0){
//				if(a[i]%2==1)k+="1";
//				else k+="0";
//				a[i]/=2;
//			}
//			string t;
//			int idx=k.size()-1;
//			while(idx!=0){
//				t+=k[idx];
//				idx--;
//			}
//			b[i]=t;
//		}
//		string s=b[1],cnt;
//		for(int i=2;i<=n;i++){
//			for(int j=0;j<=max(s.size()-1,b[i].size()-1);j++){
//				if(s[j]==b[j]&&s[j]==1)cnt+="1";
//				else cnt+="0";
//			}
//		}
//		int sum=0;
//		for(int i=0;i<=cnt.size()-1;i++){
//			if(cnt[i]=='1'){
//				int p=i;
//				if(i==1){
//					sum+=1;
//					break;
//				}int r=2;
//				while(p--){	
//					r*=2;
//				}
//				sum+=r;
//			}
//		}
//		cout<<sum;
	}
	
	return 0;
}
