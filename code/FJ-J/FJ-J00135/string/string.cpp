#include<bits/stdc++.h>
using namespace std;
struct r{
	long long a;
	char c;
};
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,sum=0;
	cin>>n;
	r p[n+1];
	for(long long i=1;i<=n;i++){
		cin>>p[i].a>>p[i].c;
		sum+=p[i].a;
	}
	bool b=0;
	if(sum%2==0) b=1;
	long long j=1,num=0;
	while(1){
		if(p[j].c==p[n].c){
			if(j=n){
				if(b){
					cout<<num;
					return 0;
				}else{
					cout<<num+p[j].a-1;
					return 0;
				}
			}
			if(n-j==1&&abs(p[j].a-p[n].a)<=1){
				if(b){
					cout<<num+p[j].a;
					return 0;
				}else{
					cout<<num+min(p[j].a,p[n].a);
					return 0;
				}
			}
			if(p[j].a==p[n].a){
				j++;
				n--;
			}else if(p[j].a<=p[n].a){
				p[n].a-=p[j].a;
				j++;
			}else{
				p[j].a-=p[n].a;
				n--;
			}
		}
		else{
			if(n-j==1&&abs(p[j].a-p[n].a)<=1){
				if(b){
					cout<<num+p[j].a;
					return 0;
				}else{
					cout<<num+min(p[j].a,p[n].a);
					return 0;
				}
			}
			if(p[j].a==p[n].a){
				num+=p[j].a;
				j++;
				n--;
			}else if(p[j].a<=p[n].a){
				num+=p[j].a;
				p[n].a-=p[j].a;
				j++;
			}else{
				num+=p[n].a;
				p[j].a-=p[n].a;
				n--;
			}
		}
	}
	return 0;
} 
