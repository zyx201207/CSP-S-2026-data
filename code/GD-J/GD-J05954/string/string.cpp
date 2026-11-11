#include<bits/stdc++.h> 
using namespace std;
void cou(string x){
	int si=x.size();
	int cnt=0;
	if(si%2==1){
		int o1=(si-1)/2;
		for(int i=o1-1,j=o1+1;i>=0;i--,j++){
			if(i!=j){
				cnt++;
			}
		}
		cout<<cnt;
	}
	if(si%2==0){
		int o2=si/2;
		for(int i=o2-1,j=o2;i>=0;i--,j++){
			if(i!=j){
				cnt++;
			}
		}
		cout<<cnt;
	}
}
int main(){
	freopen("string.in.txt","r",stdin);
	freopen("string.out.txt","w",stdout);
	string a;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		int y1;
		cin>>y1;
		string y2;
		cin>>y2;
		for(int j=1;j<=y1;j++){
			a+=y2;
		}
	}
	cou(a);
	return 0;
	
}
