#include<bits/stdc++.h>
using namespace std;
vector<long long> ele;
string to_bin(long long x){
	string b="";
	while(x>0){
		int ys=x%2;
		x/=2;
		b+=char(ys+int('0'));
	}
	string c="";
	for(int i=b.size()-1;i>=0;i--){
		c+=b[i];
	}
	return c;
}
bool sp(long long x){
	x+=1;
	while(x>1){
		if(x%2==0){
			x/=2;
		}else{
			return false;
		}
	}
	return true;
}
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout); 
	int n,m,ans=0;
	cin >> n >> m;
	bool spp=true;
	bool sp1=true;
	for(int i=0;i<n;i++){
		long long a;
		cin >> a;
		if (n==m && i==0){
			ans=a;
		}else if(n==m){
			ans=ans&a;
		}
		if(!sp(a)){
			spp=false;
		}
		if(a!=i){
			sp1=false;
		}
		ele.push_back(a);
	}
	if(n==m){
		cout << ans;
		return 0;
	}
	if(spp){
		sort(ele.begin(),ele.end(),cmp);
		cout << ele[m-1];
		return 0;
	}
	if(sp1){
		sort(ele.begin(),ele.end(),cmp);
		for(int i=0;i<m;i++){
			if(i==0){
				ans=ele[i];
			}else{
				ans=ans&ele[i];
			}
		}
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
