#include<bits/stdc++.h>

using namespace std;

int main(){
	long long a[10000000];
	string s[10000000];
	string end[10000000];
	int n;
	cin>>n;
	int count = 0;
	for(int i=0;i<n;i++){
		cin>>a[i]>>s[i];
		for(int j = 0;j<a[i];j++){
			end[j] = s[i];
		}
		count+=a[i];
	}
	int maxx = 0;
	if(count%2==0){
		int p2 = count-1;
		int p1 = 0;
		int co = 0;
		while(p1<p2){
			if(end[p1]==end[p2]){
				co++;
			}
		}
		maxx= max(co,maxx);
	}
	else{
		int p1 = 0;
		int p2 = count-1;
		int co = 0;
		while(p1!=p2){
			if(end[p1]==end[p2]){
				co++;
			}
			p1--;
			p2++;
		}
		maxx= max(co,maxx);
	}
	if(count%2==0){
		cout<<int(count/2)-maxx;
		return 0;
	}
	else{
		cout<<int(count/2)-maxx;
		return 0;
	}
}
