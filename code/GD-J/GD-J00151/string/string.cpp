#include<bits/stdc++.h>
using namespace std;
long long n,xhd;
struct node{
	long long l;
	char t;
}k[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>k[i].l>>k[i].t;
	}
	int i=1,j=n;
	while(i<j){
		if(k[i].t==k[j].t){
			if(k[i].l<k[j].l){
				k[j].l-=k[i].l;
				i++;
			}
			else if(k[j].l<k[i].l){
				k[i].l-=k[j].l;
				j--;
			}
			else{
				i++;
				j--;
			}
		}
		else{
			if(k[i].l<k[j].l){
				k[j].l-=k[i].l;
				xhd+=k[i].l;
				i++;
			}
			else if(k[j].l<k[i].l){
				k[i].l-=k[j].l;
				xhd+=k[j].l;
				j--;
			}
			else{
				xhd+=k[i].l;
				i++;
				j--;
			}
		}
	}
	cout<<xhd;
	return 0;
} 
