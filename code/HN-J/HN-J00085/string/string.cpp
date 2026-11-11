#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long a[1000005];
	string b[100005];
	string d[100005];
	int k=0;
	int g=0;
	int w=0;
	int ans=0;
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		cin>>b[i];
		w=w+a[i];
	}
	for(int i=0;i<n;i++){
		while(a[i]--){
			d[k]=b[g];
			k++;
		}
		g++;
	}
	for(int i=0;i<w/2;i++){
		if(d[i]!=d[w-1]){
			ans++; 
		}
	}
	cout<<ans;
	return 0; 
fclose(stdin);
fclose(stdout);
} 
