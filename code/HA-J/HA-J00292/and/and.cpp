#include <bits/stdc++.h>
using namespace std;
int aaa(int vv){
	int op;
	for(int i=1;i<=vv;i++){
		op=op*2;
	}
	return op;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	int s[100005],b1[100005],k=0,mod=0,max11=-1,max2;
	string h=0,b[100005][200];
	for(int i=1;i<=n;i++){
		cin>>s[i];
		for(int j=0;s[i]>=0;j++){
			if(s[i]%2==0){
				b[i][j]="1";
				s[i]/=2;
			}
			else{
				b[i][j]="0";
				s[i]=(s[i]-1)/2;
			}
			k++;
		}
		b[i][0]=h;
		b1[i]=k;
		k=0;
	}
	
	b1[0]=0;
	for(int k=1;k<=m-1;k++){
		for(int i=1;i<n;i++){
			for(int j=1;j<=min(b1[i],b1[i+1]);j++){
				if(b[i][j+(b1[i]>b1[i+1]?b1[i]-b1[i+1]:0)]==b[i+1][j+(b1[i]>b1[i+1]?0:b1[i+1]-b1[i])]){
					mod+=aaa(min(b1[i],b1[i+1])-j+1);
					mod=max(mod,b1[0]); 
				}
				max11=max(max11,mod);
			}
		}
		max2=max11;
		b1[0]=max2;
	}
	cout<<b1[0];
	return 0;
}
