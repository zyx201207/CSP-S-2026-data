#include<bits/stdc++.h>
using namespace std;
const long long N=200005;
char a[N];
string s,s1,s2;
int n,sum=0;
int a1[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a1[i]>>a[i];
		sum+=a1[i];
		for(int j=0;j<a1[i];j++){
			s[i]=a[i];
		}
	}
	int k=0,pos=0,l;
	l=sum/2;
	while(pos<l){
		for(int i=0;i<a1[k];i++){
			s1[pos]=a[k];
			pos++;
			if(pos==sum/2) break;
		}
		k++; 
	}
	for(int i=pos-1;i>=0;i--){
		s2[i]=s1[i];
	}
	int ans=0;
	if(sum%2==0){
		int j=0;
		for(int i=pos+1;i<sum;i++){
			if(s[i]!=s2[j]) ans++;
			j++;
			if(i>sum){
				break;
			}else if(j>sum){
				break;
			}
		}
		cout<<ans;
		return 0;
	}else{
		for(int i=pos+1;i<s.size();i++){
			if(s[i]!=s2[i]) ans++;
		}
		cout<<ans;
		return 0;
	}
} 
