#include<bits/stdc++.h>
using namespace std;
int arr[500500],ans[300500],vi[300500],a[300500],k;
int n,m;
void p(int st){
	k=0;
	for(int i=0;i<=m;i++){
		vi[i]=0;
		a[i]=0;
	} 
	for(int i=st;i<n;i++){
		if(vi[arr[i]]==1){
			while(1){
				if(a[k]!=arr[i]){
					vi[arr[k]]--;
					k--;
				} 
				else break;
			} 
		}else{
			k++;
			a[k]=arr[i];
			vi[arr[i]]++;
		}
	}
	for(int i=1;i<=k;i++){
		ans[a[i]]++;	
	} 
}
int main(){
	ifstream ifs("card2.in");
	ofstream ofs("card.out");
	ifs>>n>>m;
	for(int i=0;i<n;i++) ifs>>arr[i];
	
	for(int i=0;i<n;i++) p(i);
	for(int i=1;i<=m;i++) ofs<<ans[i]<<' ';
	return 0;
}
