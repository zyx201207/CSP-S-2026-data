#include<bits/stdc++.h>
using namespace std;
int a[500009],q[500009];
struct p{
	bool b[500009];
	int l[500009];
}c;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,k;
	string s;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			s+=char(48+a[j]);
			if(!c.b[a[j]])c.b[a[j]]=true;
			else{
				for(int o=c.l[a[j]];o<j;o++){
					s[o]=' ';
				}
			}
			c.l[a[j]]=j;
		}
		for(int j=0;j<n;j++){
			k=int(s[j]);
			if(int(s[j])<=47){
				continue;
			}
			cout<<k<<" "<<q[k-48]<<endl;
			q[k-49]+=1;
		}
		s="";
	}
	for(int i=0;i<m;i++){
		cout<<q[i]<<" ";
	}
return 0;
}


