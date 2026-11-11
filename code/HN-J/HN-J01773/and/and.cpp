#include<bits/stdc++.h>	
using namespace std;
int yu[1000000],yu1[1000000];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	int s[1000000];
	cin>>n>>m;
	for(int i=0;i<n;i++){
		int sh=0;
		cin>>s[i];
		int x=s[i];
		while(x>0){
			if(sh==0){
				yu1[i]+=x%2;
			}else{
				yu1[i]+=x%2*sh*10;
			}
			x=x/2;
			sh++;
		}
		s[i]+=yu1[i];
	}
	fclose(stdin);
	fclose(stdout); 
return 0;
}
