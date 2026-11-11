#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.out","w",stdout);
	freopen("card.in","r",stdin);
	int n,m,a[100005];
	cin>>n>>m;
	char c[100005],d[100005];
	int b[100005],r=0;
	for (int g=0;g<m;g++){
		for (int i=0;i<m;i++){
			cin>>a[i];
		}
		for (int i=0;i<m;i++){
			for (int j=0;j<c.size();j++){
				if (a[i]==c[j]){
					r=1;
				}
			}
			if (r!=1){
				c[i]==a[i];
			}
			else{
				for (int y=0;y<j;y++){
						d[y]=c[y];	
				}
				c=d;
				r=0;
			}
		}
		for(int i=0;i<size();i++){
			if (a[i]==c[i]){
				d[i]+=1;
			}
		}
		for (int i=0;i<c.size();i++){
			a[i]=c[i];
		}
	}
	fclose(stdout);
	fclose(stdin);
	return 0;
}
