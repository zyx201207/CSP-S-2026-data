//GZ-S00427 卢泓宇 遵义市第一中学 
#include <bits/stdc++.h>
using namespace std;
struct subway{
	int a,t;
}s[100];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    int w[m+1];
    for(int i=1;i<=m;i++){
    	cin>>w[i];
	}
	int start[q+1],end[q+1],k,k1=0;
	for(int l=1;l<=n;l++){
		cin>>k;
		k1+=k;
		for(int i=1;i<=k1;i++){
			cin>>s[i].a>>s[i].t;
			s[i].t+=w[s[i].a]; 
		}	
	}
	for(int i=1;i<=q;i++){
		cin>>start[i]>>end[i];
	}
	int c,e;
	bool bo=0;
	for(int v=1;v<=q;i++){
		for(int i=1;i<=k1;i++){
		   for(int j=i+1;j<=k1;j++){
		   	if(s[i].a==s[j].a){
		   		c=i;
		   		e=j;
		   		bo=1;
		   		break;
			   }
		   }
		   if(bo==1){
		   	  break;
		   } 
	}
	int num=0;
	for(int i=1;i<=c;i++){
		num+=s[i].t; 
	}
	for(int i=e;i<=k1;++i){
		num+=s[i].t; 
	}
	}
	cout<<num;
	fclose(stdin);
	fclose(stdout);
}

