//GZ-J00485 ³Â×ÓÐù
#include<bits/stdc++.h>
using namespace std;
long long n,m,sum=0;
long long a[1000000],b[1000000],c[1000000];
stack<int>s;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int g=1;g<=n;g++){
		for(int i=1;i<=m;i++){
			b[i]=0;
		}
		for(int i=g;i<=n;i++){
			b[a[i]]++;
			s.push(a[i]);
			if(b[a[i]]==2){
				s.pop();
				b[a[i]]=1;
				int p=s.top();
				while(p!=a[i]&&!s.empty()){
					b[p]--;
					s.pop();
					p=s.top();
				}
				s.pop();
				s.push(a[i]);
			}
		}
		while(!s.empty()){
			c[s.top()]++;
			s.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
	return 0;
}
