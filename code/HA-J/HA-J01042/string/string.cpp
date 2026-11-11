#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	long long a[200010];
	char c[200010];
	string b;
	int l=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		for(int j=1;j<=a[i];j++){
			b+=c[i];
		}
	}
	l=b.size();
	for(int i=0;i<=l/2;i++){
		if(b[i]==b[l-i-1]){
			if(i==l/2){
				cout<<0;
				return 0;
			}
			else{
				continue;
			}
			
		}
		else{
			break;
		}
	}
	cout<<l/2;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
