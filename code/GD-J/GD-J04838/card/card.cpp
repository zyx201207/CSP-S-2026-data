#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int card[n];
	for(int i=0;i<n;i++)cin>>card[i];
	int livem[m]={0};
	
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			bool live=true;
			bool killleft[m]={false};
			killleft[card[i]-1]=true;
				for(int left=j-1;left>=i;left--){
					killleft[card[left]-1]=true;
				}
				for(int right=j+1;right<n;right++){
					if(killleft[card[right]-1]){
						live=false;
						break;
					}
				}
				if(live){
					livem[card[j]-1]++;
				}
		}
	}
	for(int i=0;i<m-1;i++)cout<<livem[i]<<' ';
	cout<<livem[m-1];
	return 0;
}
