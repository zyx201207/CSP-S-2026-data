#include<bits/stdc++.h>
using namespace std;
int n;
int shu[200005];
long long he;
char zhi[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>shu[i]>>zhi[i];
    int l=1,r=n;
    while(l!=r){
   	    if(shu[l]>shu[r]){
	   		if(zhi[l]==zhi[r])shu[l]-=shu[r],r--;
			else he+=shu[r],shu[l]-=shu[r],r--;
		}else if(shu[l]==shu[r]){
			if(zhi[l]==zhi[r])r--,l++;
			else he+=shu[l],r--,l++;
		}else{
			if(zhi[l]==zhi[r])shu[r]-=shu[l],l++;
			else shu[r]-=shu[l],l++,he+=shu[l];
		}
	}
	cout<<he;
	return 0;
}