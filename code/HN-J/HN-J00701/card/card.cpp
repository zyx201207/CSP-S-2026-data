#include <bits/stdc++.h>
using namespace std;
int l[10005];
int n[10005];
int a,b;
int search(){
	for(int i=0;i<a;i++){
		for(int j=0;j<a;j++){
			if(l[i]==l[j]){
				return j;
			}
		}
	}
}
int play(int num){
	int cnt=0;
	int cc=0;
	for(;;){
		if(num==b){
			return 0;
		}
		for(int i=num-1;i<a;i++){
			int t=search();
			for(int j=search()+1;j<a;j++){
				n[cnt]=l[j];
				for(int m=0;m<=a-j-1;m++){
					if(m=i){
						cc++;
					}
				}
			}
			
		}
		cout<<cc<<" ";
		play(num+1);
	}
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>a>>b;
	for(int i=0;i<a;i++){
		cin>>l[i];
	}
	play(0);
	return 0;
} 
