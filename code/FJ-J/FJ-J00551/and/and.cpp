#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int s[100005];
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	int x=0;
	for(int i=1;i<n;i++){
		x+=i;
	}
	int min=0,max=0;
	for(int i=1;i<=x;i++){
		for(int j=1;j<=x-j;j++){
			min=((s[i])&=(s[i+j]));
			if(min>max){
				max=min;
			}
			min=0;
		}
	}
	cout<<max;
	return 0;
}
