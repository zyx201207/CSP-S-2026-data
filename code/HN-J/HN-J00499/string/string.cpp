#include<bits/stdc++.h>
using namespace std;
struct jj{
	int x;
	char ch;
}a[200100];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    long long h=0;
    cin>>n;
    for(int i=1;i<=n;i++){
    	cin>>a[i].x;
    	cin>>a[i].ch;
	}
	for(int i=1,j=n;i<=j;i++,j--){
		if(j==i){
			if(a[i].x%2==1){
				cout<<h+1;
				return 0;
			}
			else{
				cout<<h;
				return 0;
			}
		}
		if(a[i].ch!=a[j].ch){
			if(a[i].x>a[j].x){
				h+=a[j].x;
				a[i].x-=a[j].x;
				a[j].x=0;
				i--;
				continue;
			}
			if(a[i].x<a[j].x){
				h+=a[i].x;
				a[j].x-=a[i].x;
				a[i].x=0;
				j--;
				continue; 
			}
			if(a[i].x==a[j].x && a[i].ch!=a[j].ch)\
			  h+=a[i].x;
		}
	}
	cout<<h;
	return 0;
}

