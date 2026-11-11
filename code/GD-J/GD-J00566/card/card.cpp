#include <bits/stdc++.h>
using namespace std;


int a[500005],t[500005];
string s;

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		
		for(int j=i;j<=n;j++){
			char c=(a[j]+'0');
			for(int x=0;x<s.size();x++){
				if(s[x]==c){
					string s1=s.substr(0,x);
					s=s1;
					break;
				}
			}
			s=s+c;
		}
		for(int x=0;x<s.size();x++){
			t[int(s[x]-'0')]++;
		}
		
		s="";
	}
	
	for(int i=1;i<=m ;i++){
		printf("%d ",t[i]);
	}
	return 0;
} 
