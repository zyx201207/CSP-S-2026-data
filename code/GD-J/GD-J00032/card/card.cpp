#include<bits/stdc++.h>
using namespace std;
int num[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	string cs=" ";
	cin>>n>>m;
	char cd[m+1];
	int len;
	for(int i=1;i<=n;i++)
		cin>>cd[i];
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			len=cs.size();
			for(int k=1;k<=len;k++){
				if(cs[k]==cd[j]){
					for(int l=k;l<=len;l++){
						cs[k]=' ';
					}
				}
			}
			cs+cd[j];
		}
		for(int j=1;j<=len;j++){
			num[cs[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<num[i]<<' ';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
