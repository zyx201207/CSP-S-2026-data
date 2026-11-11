#include<bits/stdc++.h>
using namespace std;
int a[10000005],b[10000005];
int main(){
	freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m,s[15];
    cin>>n>>m;
    s[1]=0,s[2]=0;
    for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int x=a[1];
	int y=0;
	while(y==0){
		int i=2;
		if(a[i]!=x){
			y=a[i];
		}
		i++;
	}
    for(int i=1;i<=n;i++){
		if(a[i]==x){
			s[1]++;
			if(a[n]==y){
				s[2]++;
			}
		}
		else if(a[i]==y){
			s[2]++;
			if(a[n]==x){
				s[1]++;
			}
		}
	}
	cout<<s[1]<<' '<<s[2];
    return 0;
}
