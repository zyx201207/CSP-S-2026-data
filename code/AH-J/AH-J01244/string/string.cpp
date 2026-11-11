#include<bits/stdc++.h>
using namespace std;

struct str{
	long long a1;
	char c1;
};

int main(){
	freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    int n;
	cin>>n;
	str S1[200010];
	long long cnt=0,g=0;
	string s;
	
	bool different=true;
	char z=S1[0].c1;
	
	for(int i=0;i<n;i++){
		cin>>S1[i].a1>>S1[i].c1;
		cnt+=S1[i].a1;
		
		if(S1[i].c1!=z){
			different=false;
		}
		
		for(int j=0;j<S1[i].a1;j++){
			s=s+S1[i].c1;
		}z=S1[i].c1;
	}
	
	if(different){
		cout<<"0";
		return 0;
	}
	
	char left,right;
	
	for(int i=0;i<=cnt/2;i++){
		left=s[i];
        right=s[cnt-i-1];
        
        if(left == right){
            continue;
        }
        g++;
	}
	cout<<g;

	return 0;
}
