#include<bits/stdc++.h>
using namespace std;
#define int long long
string s;
struct kskbl{
	int a;
	string c;
}m[300000];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;cin>>n;
	for(int i=1;i<=n;i++){
		cin>>m[i].a>>m[i].c;
	}
	int sum=0; 
	for(int i=1,j=n;i<=j;){
		if(m[i].c==m[j].c){
			if(m[i].a>m[j].a){
				j--;
			}else if(m[i].a<m[i].a){
				i++;
			}else if(m[i].a==m[j].a){
				j--;
				i++;
			}
		}
		else{
			if(m[i].a>m[j].a){
				sum+=m[j].a;
				m[i].a-=m[j].a;
				j--;
			}
			else if(m[i].a<m[j].a){
				sum+=m[i].a;
				m[j].a-=m[i].a;
				i++;
			}else if(m[i].a==m[j].a){
				sum+=m[i].a;
				i++;
				j--;
			}
		}
	}
	cout<<sum<<endl;
	return 0;
} 
