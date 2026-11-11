#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005];
map<int,int>mp;
map<int,int>mp1;
map<int,int>::iterator it;
int main(){
freopen("card.in","r",stdin);
freopen("card.out","w",stdout);
cin>>n>>m;
for(int i=1;i<=n;i++){
	cin>>a[i];}
	for(int i=1;i<=n;i++){
    for(it=mp.begin();it!=mp.end();it++)
    mp[it->first]=0;
		int k=i;
    while(k<=n){
		if(mp[a[k]]!=0){			
			for(int j=mp[a[k]];j<k;j++){
				mp[a[j]]=0;
				}
			}	
			mp[a[k]]=k;	
			k++;
}
    for(it=mp.begin();it!=mp.end();it++)
    if(it->second!=0)
    mp1[it->first]++;
}
    for(it=mp1.begin();it!=mp1.end();it++)
    cout<<it->second<<" ";
fclose(stdin);
fclose(stdout);
return 0;
}
