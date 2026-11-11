#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=2e5+10;
int n;
char c[N];
int a[N];
int cnt;
int cd;
int ans=0;//Trick||Treat!
bool cmp(int a,int b){
	return a<b;
}
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		
		if(i=1)cd=a[i];
		if(i>1){
			cd=__gcd(cd,a[i]);
		}
		if(i>1&&c[i-1]!=c[i])ans=1;
	}
	if(ans==0){
		cout<<ans;
		return 0;
	}
	int g=0;
	if(cd!=1){
		for(int i=1;i<=n;i++){
			a[i]=a[i]/cd;
			cnt+=a[i];
		}
	}
	if(cnt%2==1){
		for(int i=1;i<=n;i++){
			g+=a[i];
			if(g>=cnt){
				a[i]--;
				cnt--;
				break;
			}
		}
	}
	string s1,s2;
	
	for(int i=1;i<=n;i++){
		while(s1.size()==cnt/2&&a[i]>0){
			a[i]--;
			s2+=c[i];
		}
		while(a[i]--)s1+=c[i];
		int d=0;
		int kk=s1.size();
		while(kk>cnt/2){
			kk--;
			
			d++;
		}
		while(d--){
			s2+=c[i];
		}
	}
	if(s1==s2){
		cout<<0;
		return 0;
	}
	int f=0;
	for(int i=0;i<cnt/2;i++){
		if(s1[i]!=s2[i])f++;
	}
	cout<<f;
	return 0;
} 
