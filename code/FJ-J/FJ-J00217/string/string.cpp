#include <bits/stdc++.h>
using namespace std;
vector<long long> a;
vector<char> b;
long long ans=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 
	int n;
	cin>>n;
	char c='0';
	for(int i=1;i<=n;i++){
		int a1;
		char b1;
		cin>>a1>>b1;
		if(b1==c){
			a[a.size()-1]+=a1;
		}
		else{
			b.push_back(b1);
			a.push_back(a1);
			c=b1;
		}
	}
	for(int i=0,j=a.size()-1;i<j;){
		if(b[i]==b[j]){
			if(a[i]>a[j]){
				a[i]-=a[j];
				j--;
			}
			if(a[j]>a[i]){
				a[j]-=a[i];
				j--;
			}
			if(a[i]==a[j]){
				i++;
				j--;
			}
		}
		else if(b[i]!=b[j]){
			if(a[i]>a[j]){
				a[i]-=a[j];
				ans+=a[j];
				j--;
			}
			if(a[j]>a[i]){
				a[j]-=a[i];
				ans+=a[i];
				j--;
			}
			if(a[i]==a[j]){
				ans+=a[i]; 
				i++;
				j--;
			}			
		}
	}
	cout<<ans;
}
