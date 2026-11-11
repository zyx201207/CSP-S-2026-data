#include<bits/stdc++.h> 
using namespace std;

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
    int ans[]={0};
	int flag[]={0};
	int flag_seat[]={0};
	int last=0;
	for(int i=0;i<n;i++){
		int a;
		cin>>a;
		if(flag[a]==1){
			last=flag_seat[a];
			for(int j=0;j<m;j++){
				if(flag_seat[j]>last){
					flag_seat[j]=0;
					flag[j]=0;
				}
			}
		}else{
			last++;
			flag_seat[a]=last-1;
			flag[a]=1;
		} 
		for(int j=0;j<m;j++){
			if(flag[j]){
				ans[j]++;
			}
		}
	}
	for(int i=0;i<m;i++){
		cout<<ans[i];
		if(i<m-1){
			cout<<" ";
		}
	}
	cout<<endl;
	return 0;
}
