#include<bits/stdc++.h>
using namespace std;
long long n;
struct N{
	long long a;
	char c;
}s[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i].a>>s[i].c;
		
	}
	long long cnt=0;
	long long sum=n;
	
	for(int i=1;i<=n;i++){
	long long ss=0;
		for(int j=sum;j>=i;j--){
			if(s[i].c==s[j].c){
				if(s[i].a>s[j].a){
					s[i].a-=s[j].a;
					s[j].a=0;
					ss+=1;
				}
				else if(s[i].a==s[j].a){
					s[i].a=0;
					s[j].a=0;
					sum-=1;
					break; 
				}
				else{
					s[j].a-=s[i].a;
					s[i].a=0;
					break;
				}
			}else{
				if(s[i].a>s[j].a){
					s[i].a-=s[j].a;
					cnt+=s[j].a;
					s[j].a=0;
					ss+=1;
				}
				else if(s[i].a==s[j].a){
					s[i].a=0;
					cnt+=s[j].a;
					s[j].a=0;
					sum-=1;
					break;
				}
				else{
					s[j].a-=s[i].a;
					cnt+=s[i].a;
					s[i].a=0;
					break;
					
				}
			}
		}
		sum-=ss;
	}
	cout<<cnt;
	
	return 0;
} 
