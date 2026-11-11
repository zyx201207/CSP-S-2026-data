//GZ-J00432 贵阳市第三十四中学 杨宗泽 
#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[300005],k=1,y,cn1,cn2;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		cout<<n;
		return 0;
	}
	else{
		b[1]=a[1];
		for(int j=1;j<=n;j++){
		    for(int i=k;i<=n;i++){
			    if(a[i]==b[1]){
				    if(b[2]!=0){
				    	b[1]=b[2];
				    	b[2]=a[i];
					}
			    }
			    else if(a[i]==b[2]){
				    b[1]=a[i];
				    b[2]=0;
			    }
			    else{
			    	b[2]=a[i];
			    }
		    }
		    k++;
			for(int i=1;i<=2;i++){
				if(b[i]==1){
					cn1++;
				}
				if(b[i]==2){
					cn2++;
				}
			}	
		}
	}
	cout<<cn1<<" "<<cn2;
	return 0;
}
