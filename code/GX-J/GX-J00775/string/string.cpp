#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int s[i]={0};
	int a[i]={0},sum=0;
	for(int i=1;i=n;i++){
			cin>>s[i];
			cin>>a[i];
			if(a[i]==a[i+1]){
				sum=sum+s[i];
			}else{
				break;
			}
		}
		cout<<sum;
return 0;
}
