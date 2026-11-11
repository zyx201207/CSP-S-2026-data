#include<bits/stdc++.h>
using namespace std;
int a[200004],a1,sum=0;
char b[200003],b1;
bool e=1;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
cin.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
	cin>>a[i]>>b[i];
	}
	int x=1;
	while(n-x>=0){
		a1=a[x];
		b1=b[x];
		while(a1!=0){
			if(e==1){
				if(b1==b[n]){
				if(a1>=a[n]){
					a1=a1-a[n];
					if(n-x==1){
						sum=sum+min(a1,a[n]);
					}
					else if(n-x!=0){
						sum=sum+a1;
					}
					e=1;
					n--;
				}
				else {
					a1=a[n]-a1;
					if(n-x<=1){
					sum=sum+min(a[x],a[n]);
					}
					else {
						sum=sum+a1;
					}
					e=0;
					x++;
				}
			}
			else {
				if(a1>=a[n]){
					a1=a1-a[n];
					sum=sum+a1;
					e=1;
					n--;
				}
				else {
					a1=a[n]-a1;
					sum=sum+a1;
					b1=a[n];
					e=0;
					x++;
				}
			}
			}
			else{
				if(b1==b[x]){
				if(a1>=a[x]){
					a1=a1-a[x];
					a1=a1-a[n];
					if(n-x==1){
						sum=sum+min(a1,a[n]);
					}
					else if(n-x!=0){
						sum=sum+a1;
					}
					e=1;
					n--;
				}
				else {
					a1=a[x]-a1;
					sum=sum+a1;
					e=0;
					x++;
				}
			}
			else {
				if(a1>=a[x]){
					a1=a1-a[x];
					sum=sum+a1;
					e=1;
					n--;
				}
				else {
					a1=a[x]-a1;
					sum=sum+a1;
					b1=a[x];
					e=0;
					x++;
				}
			}
			}
			}
		}
	cout<<sum;
			return 0;
	}



