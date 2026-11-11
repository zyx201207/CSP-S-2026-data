#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5;
int n;
vector<int> a;
//vector<char> s;
string s;
int ans=0;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		char y;
		cin>>x>>y;
		for(int i=1;i<=x;i++){
			s+=y;
		}
//		int si=s.size();
//		int ai=a.size();
//		if(y==s[si-1]){
//			a[ai-1]+=x;
//		}else{
//			a.push_back(x);
//			s.push_back(y);
//		}
	}
	int siz=s.size();
	for(int i=0;i<siz/2;i++){
		//cout<<s[i];
		int j=siz-i-1;
		if(s[i]!=s[j])ans++; 
	}
//	int l=1;
//	for(int  i=0;i<siz/2;i++){
//		int j=siz-i-1;
//		if(s[i]==s[j]){
//			int mor=a[i]-a[j];
//			if(a[j-1]>mor){
//				a[j-1]-=mor;
//			}else{
//				a[j-1]=0;
//				mor-=a[j-1];
//				ans+=mor;
//				siz--;
//				a[j-1]=-mor;
//			}
//			
//			
//		}else{
//			int mor=a[i]-a[j];
//			if(a[j-1]==a[i]){
//				
//			}
//			if(a[j-1]>mor){
//				a[j-1]-=mor;
//			}else{
//				a[j-1]=0;
//				mor-=a[j-1];
//				ans+=mor;
//				siz--;
//				a[j-1]=-mor;
//			}
//		}
//	}
	cout<<ans;
	//4 3 a 2 c 1 b 2 a
	return 0;
}
