#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int have[500005]={0};
int wei[500005]={0};
int qian=0;
int ju[500005];
void han(int x){
	for(int i=x;i<=n;i++){
		if(have[a[i]]==0){
			have[a[i]]=1;
			wei[a[i]]=i;
		}
		else if(have[a[i]]){
			qian+=i-wei[a[i]];
			for(int j=wei[a[i]];j<i;j++){
				have[a[j]]=0;
			
			}
			have[a[i]]=1;
			wei[a[i]]=i;
		}
		
	}
	for(int i=qian+x;i<=n;i++){
		ju[a[i]]+=1;
	}
	return;
}

int main(){
	//feropen("card.in","r",stdin);
	//feropen("card.out","w",stdout);
	
	for(int i=1;i<=n;i++){
		han(i);
		have[500005]={0};
		wei[500005]={0};
		qian=0;
	}
	long long l=1;
	while(l<=m){
		cout<<ju[l]<<" ";
		l++;
	}
	
	
	return 0;
}
