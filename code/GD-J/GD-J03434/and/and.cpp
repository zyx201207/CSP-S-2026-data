#include<bits/stdc++.h>
using namespace std;
string tob(int a){
	int k=floor(log2(a));
	string ans="";
	for(int i=k;i>=0;i--){
		if(pow(2,i)<=a){
			ans+="1";
			a-=pow(2,i);
		}else{
			ans+="0";
		}
	}
	return ans;
}
int bto(string a){
	int ans=0;
	for(int i=0;i<a.size();i++){
		if(a[i]-'0'){
			ans+=pow(2,a.size()-i-1);
		}
	}
	return ans;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	vector<int> a(n);
	int mn=-1;
	for(int i=0;i<n;i++){
		cin>>a[i];
		mn=max(mn,a[i]);
	}
	if(m==1){
		cout<<mn;
		return 0;
	}
	int ml=tob(mn).size();
	vector<string> a2(n);
	vector<string> a3(n);
	int k;
	for(int i=0;i<n;i++){
		k=ml-tob(a[i]).size();
		while(k--){
			a2[i]+="0";
		}
		a2[i]+=tob(a[i]);
	}
	int cnt;
	int ro=0;
	for(int i=0;i<ml;i++){
		if(ro%2){
			a2.clear();
			cnt=0;
			for(int j=0;j<n;j++){
				if(a3[j][i]=='1'){
					cnt++;
					a2.push_back(a3[j]);
				}
				if(cnt>=m){
					ro++;
				}
			}
		}else{
			a3.clear();
			cnt=0;
			for(int j=0;j<n;j++){
				if(a2[j][i]=='1'){
					cnt++;
					a3.push_back(a2[j]);
				}
				if(cnt>=m){
					ro++;
				}
			}
		}
	}
	int ans;
	if(ro%2){
		ans=bto(a3[0]);
		for(int i=1;i<a3.size();i++){
			ans&=bto(a3[i]);
		}
	}else{
		ans=bto(a2[0]);
		for(int i=1;i<a2.size();i++){
			ans&=bto(a2[i]);
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
