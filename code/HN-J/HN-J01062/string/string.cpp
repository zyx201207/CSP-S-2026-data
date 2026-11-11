#include<bits/stdc++.h>
using namespace std;
string s1[200005],s2[200005];
long long a[200005],sum=0;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int n,l=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s1[i];
		l+=a[i];
	}
	int t=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++) s2[++t]=s1[i];
	} 
	for(int i=1;i<=l/2;i++){
		if(s2[i]!=s2[l+1-i]){
			s2[l+1-1]=s2[i];
			sum++;
		}
	}
	cout<<sum;
	return 0;
}
