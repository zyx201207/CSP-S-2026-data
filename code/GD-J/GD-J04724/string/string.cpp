#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int n,mingcd=0x7fffffff;
long long step;
string str;
bool f;
bool check(string s){
	for(int i=0;i<static_cast<int>(s.length()/2);i++){
		if(s.at(i)!=s.at(s.length()-i-1)){
			return false;
		}
	}
	return true;
}

int GCD(int a,int b){
	int t=0;
	while(t){
		t=a%b;
		a=b;
		b=t;
	}
	return a;
}

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin>>n;
	vector<pair<int,char>> v;
	while(n--){
		int m;
		char c;
		cin>>m>>c;
		v.push_back(pair<int,char>({m,c}));
	}
	for(int i=0;i<static_cast<int>(v.size()-1);i++){
		int gcd=GCD(v.at(i).first,v.at(i+1).first);
		if(gcd==1){
			break;
			f=true;
		}else{
			mingcd=min(mingcd,gcd);
		}
	}
	if(!f){
		for(int i=0;i<static_cast<int>(v.size());i++){
			v.at(i).first/=mingcd;
		}
	}
	for(int i=0;i<static_cast<int>(v.size());i++){
		for(int j=0;j<v.at(i).first;j++){
			str+=v.at(i).second;
		}
	}
	if(check(str)){cout<<0;return 0;}
	for(int i=0;i<static_cast<int>(str.length()/2);i++){
		if(str.at(i)!=str.at(str.length()-i-1)){
			step++;
		}
	}
	cout<<step*mingcd;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
