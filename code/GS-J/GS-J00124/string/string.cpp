#include<bits/stdc++.h>
using namespace std;
long long l,k;
const int N = 2e5+10;
struct node{
	int a;
	char c;
}b[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>b[i].a>>b[i].c;
		l+=b[i].a;
	}
	l=(l+1)/2;
	int j=n;
	for(int i=1;i<=j;i++){
	
		if(b[j].a<b[i].a){
			if(b[j].c!=b[i].c){
			k+=b[j].a;
			}
			
			b[i].a-=b[j].a;
			j--;
			i--;
		}else if(b[j].a==b[i].a){
			if(b[j].c!=b[i].c){
				k+=b[j].a;	
			}
			j--;
		}else{
			if(b[j].c!=b[i].c){
				k+=b[i].a;	
			}
			b[j].a-=b[i].a;
		}
		
	}
	cout<<k;
	return 0;
}
