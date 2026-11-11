#include<bits/stdc++.h>
using namespace std;
unsigned long long n,cnt;
struct aaa{
	unsigned long long a;
	char c; 
}p[200005];
int main(){
	cin>>n;
	for(long long i=0;i<n;i++){
		cin>>p[i].a>>p[i].c;
	}
	unsigned long long i=0,j=n-1;
	while(i<=j){
		if(p[i].c!=p[j].c){
			cnt+=min(p[i].a,p[j].a);
			if(p[i].a>p[j].a){
				p[i].a-=p[j].a;
				j--;
			}else if(p[i].a==p[j].a){
				i++;
				j--;
			}else{
				p[j].a-=p[i].a;
				i++;
			}
		}else{
			if(p[i].a>p[j].a){
				p[i].a-=p[j].a;
				j--;
			}else if(p[i].a==p[j].a){
				i++;
				j--;
			}else{
				p[j].a-=p[i].a;
				i++;
			}
		}
	}
	cout<<cnt;
}
