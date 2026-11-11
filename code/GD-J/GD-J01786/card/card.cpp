#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int x,y;
	stack<int>s;
	cin>>x>>y;
	int arr[x],brr[y+2]={},ans[y+2]={};
	for(int i=0;i<x;i++)cin>>arr[i];
	for(int i=0;i<x;i++){
		for(int j=i;j<x;j++){
			if(brr[arr[j]]==0){
				s.push(arr[j]);
				brr[arr[j]]=1;
			}else{
				while(!s.empty()&&s.top()!=arr[j]){
					brr[s.top()]=0;
					s.pop();
				}
			}
	}for(int j=0;j<y+2;j++)if(brr[j]!=0)ans[j]++;
		memset(brr,0,sizeof(brr));
	}for(int i=1;i<=y;i++)cout<<ans[i]<<' ';
	fclose(stdin);
	fclose(stdout);
}
