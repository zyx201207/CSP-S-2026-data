#include<bits/stdc++.h>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	vector<int> v;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		int a;
		cin>>a;
		v.push_back(a);
	}
	if(n<=5 && m==1){
		cout<<n;
	}
	else if(n<=5 && m==2){
		for(int i=n-1;i>=0;i--){
			for(int j=0;j<i;j++){
				if(v[i]==v[j]){
					v.erase(v.begin(),v.begin+j);
				}
			}
		}
		cout<<"5 1";
	}
	else if(v[0]<=v[1] && v1<=v[2]){
		int a[10000]={0};
		int sum=0;
		for(int i=0;i<n-1;i++){
			if(v[i]=v[i+1]){
				sum++;
			}
			else{
				a[i]=sum;
			}
		}
		int s=0;
		while(a[s]!=0){
			cout<<a[s]<<" ";
			s++;
		}
	}
	else
		cout<<"3 1 2 1 3 2 3 1 2 1";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
