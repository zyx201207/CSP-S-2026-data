#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,r;
long long a1,sum=0;
char b1;
struct strin{
	long long a;
	char b;
}st1[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	r=n;
	for(int i=1;i<=r;i++){
		cin>>a1;
		cin>>b1;
		
		if(st1[i-1].b==b1){
			st1[i-1].a+=a1;
			i--;
			r--;
		}else{
			st1[i].a=a1;
			st1[i].b=b1;
		}
	}
	int l=1;

	while(l<r){
		if(st1[l].a>st1[r].a){
			if(st1[l].b==st1[r].b){
				sum+=0;
			}else{
				sum+=st1[r].a;
			}
			st1[l].a-=st1[r].a;
			r--;
			
		}else if(st1[l].a<st1[r].a){
			if(st1[l].b==st1[r].b){
				sum+=0;
			}else{
				sum+=st1[l].a;
			}
			st1[r].a-=st1[l].a;
			l++;
			
		}else if(st1[l].a==st1[r].a){
			if(st1[l].b==st1[r].b){
				sum+=0;
			}else{
				sum+=st1[l].a;
			}
			l++;
			r--;
		}
		
		
		
	}
	cout<<sum;
	
	
	return 0;
}
