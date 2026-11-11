#include<bits/stdc++.h>
using namespace std;
struct aaa{
	long long int a;
	char c; 
};
const int N=200000+5;
long long int n,t=0;
aaa s[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>s[i].a>>s[i].c;
	long long int j=n,i=1;	
	while(i<j){
		if(s[i].c!=s[j].c){
			if(s[i].a<s[j].a){
				t=t+s[i].a;
				s[j].a-=s[i].a;
				i++;
			} 
			else if(s[i].a>s[j].a){
				t=t+s[j].a;
				s[i].a-=s[j].a;
				j--;
			}
			else{
				t=t+s[i].a;
				i++;
				j--;
			}
		} 
		else{
			if(s[i].a<s[j].a){
				s[j].a-=s[i].a;
				i++;
			} 
			else if(s[i].a>s[j].a){
				s[i].a-=s[j].a;
				j--;
			}
			else{
				i++;
				j--;
			}
		}
	}
	cout<<t;
	return 0;
}

