#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int a[500005],b[500005],u[300005],c,d,w=0;
	bool p[500005]={0};
	cin>>c>>d;
	for(int i=1;i<=c;i++){
		cin>>a[i];
	}
	for(int k=0;k<c;k++){
		for(int i=k+1;i<=c;i++){
			if(p[a[i]]==0){
				w++;
				p[a[i]]=1;
				b[w]=a[i];
			}else{
				bool s=0;
				int s1=0;
				for(int j=1;j<=w;j++){
					if(s==1){
						b[j]=0;
						s1++;
					}
					if(b[j]==a[i]){
						s=1;
						b[j]=0;
						s1++;
					}
				}
				w-=s1;
				for(int j=1;j<=d;j++){
					p[j]=0;
				}
				for(int j=1;j<=w;j++){
					p[b[j]]=1;
				}
				w++;
				p[a[i]]=1;
				b[w]=a[i];
			}
		}
		for(int i=1;i<=d;i++){
			if(p[i]!=0){
				u[i]++;
			}
			p[i]=0;
		}
		for(int i=1;i<=w;i++){
			b[i]=0;
		}
	}
	for(int i=1;i<=d;i++){
		cout<<u[i]<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
