#include<bits/stdc++.h>
using namespace std;
int a[200005];
char c[200005];
long long dd[200005];
long long cc[200005];
string s;
int main(){
	freopen("string.in","r",stdin);
 	freopen("string.out","w",stdout);
 	int n;cin>>n;
 	bool vis=0;
	long long ans=0;
 	for(int i=0;i<n;i++){
 		cin>>a[i]>>c[i];
 		dd[c[i]]+=a[i];
 		if(i>0&&c[i]!=c[i-1]) vis=1;
	}
 		
	if(!vis){
		cout<<0;
		return 0;
	}
	int kk=0;
	for(int i=0;i<200005;i++){
		if(dd[i]!=0){
			cc[kk]=dd[i];
			kk++;
		}
	}
	if(kk==1){
		cout<<0;
		return 0;
	}
	if(kk==2){
		cout<<min(cc[0],cc[1]);
		return 0;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<a[i];j++){
 			s+=c[i];
		}
	}
	int g=n;
	int h=s.size(); 
	int l=0,r=h-1;
	while(1){
		if(s[l]!=s[r])ans++;
		l++;r--;
		if(l>=r)break;
	}
	cout<<ans;
 }
