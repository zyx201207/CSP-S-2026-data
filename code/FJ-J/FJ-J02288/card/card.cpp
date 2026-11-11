#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	char a[n];
	int b[m]={0};
	for(int i=0;i<n;i++){
		scanf("%s",&a[i]);
	}
	for(int i=0;i<n;i++){
		string s="";
		for(int j=i;j<n;j++)
		{
			int s1=s.find(a[j]);
			if(s1>=0){
				while(s1<n){
					s[s1]=0;
					s1--;
				}
			}else{
				s+=a[j];
			}
		}
		for(char j:s){
			int k=j-'0';
			b[k-1]+=1;
		}
	}
	for(int i=0;i<m;i++){
		printf("%d",b[i]);
	}
	return 0;
}
