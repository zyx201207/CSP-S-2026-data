#include<bits/stdc++.h>
using namespace std;
const int N=200008;
struct node{
	long long x;
	char s;
};
node a[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	for(int i=0;i<n;i++) cin>>a[i].x>>a[i].s;
	int i=0,j=n-1;
	unsigned long long cnt=0;
	while(i<j){
		if(a[i].s==a[j].s){
			if(a[i].x<a[j].x){
				a[j].x-=a[i].x;
				i++;
			}
			else if(a[i].x>a[j].x){
				a[i].x-=a[j].x;
				j--;
			}
			else{
				i++;
				j--;
			}
		}
		else{
			if(a[i].x<a[j].x){
				a[j].x-=a[i].x;
				cnt+=a[i].x;
				i++;
			}
			else if(a[i].x>a[j].x){
				a[i].x-=a[j].x;
				cnt+=a[j].x;
				j--;
			}
			else{
				cnt+=a[j].x;
				i++;
				j--;
			}
		}
	}
	cout<<cnt<<endl;
	return 0;
} 
