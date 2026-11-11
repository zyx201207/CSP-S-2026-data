#include<bits/stdc++.h>
using namespace std;
long long a,s,arr[500010],srr[500010],ans=0,num=0;
bool shiA=1,shiB=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >>a>>s;
	for (int i=0; i<a; i++){
		cin >>arr[i];
		if (arr[i]!=i+arr[0]){
			shiA=0;
		}
	}
	if (shiA){
		long long ans=1,z=1;
		while (s>0){
			s-=z;
			z++;
			ans++;
			if (ans==a){
				break;
			}
		}
		if (s<0){
			cout <<ans-1;
		}else{
			cout <<ans;
		}
		return 0;
	}
	long long v=arr[1]-arr[0];
	for (int i=1; i<a; i++){
		if (arr[i]-arr[i-1]!=v){
			shiB=0;
		}
	} 
	if (shiB){
		long long ans=1,z=arr[1]-arr[0],b=arr[1]-arr[0];
		while (s>0){
			s-=z; 
			z+=b;
			ans++;
			if (ans==a){
				break;
			}
		}
		if (s<0){
			cout <<ans-2;
		}else{
			cout <<ans-1;
		}
	}
	sort(arr,arr+a);
	for (int i=1; i<a; i++){
		long long flag=arr[i];
		for (int o=i-1; o>=0; o--){
			if (s-(flag-arr[o])>=0){
				s-=flag-arr[o];
				num++;
			}else{
				break;
			}
		}
		ans=max(ans,num);
	}
	cout <<ans;
	return 0;
} 
