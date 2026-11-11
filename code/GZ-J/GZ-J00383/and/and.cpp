//GZ-J00383 邓智豪 兴义市弘毅中学 
#include<bits/stdc++.h>
const int MAXN=2e5+50,MAXM=2e5+50;
using namespace std;

int a[MAXN];
int n,m;
int ans;
bool A=1;

string toBin(int i,int size=0){
	string res="0";
	stack<char> tmp;
	while(i>0){
		tmp.push(i%2==0?'0':'1');
		i/=2;
		size--;
	}
	while(size>0){
		tmp.push('0');
		size--;
	}
	while(!tmp.empty()){
		res.push_back(tmp.top());
		tmp.pop();
	}
	return res;
}

string operator+(const string& s,int i){
	string str=s;
	int size=str.size()-1;
	if(str[size]=='0'){
		str[size]='1';
	}else{
		for(int i=size;i>=0;i--){
			if(str[i]=='1') str[i]='0';
			else{
				str[i]='1';
				break;
			}
		}
	}
	if(count(str.begin(),str.end(),'1')==0){
		str[0]='1';
		str.push_back('0');
	}
	return str;
}

bool operator<(const string& s1,const string& s2){
	if(s1.size()!=s2.size()) return s1.size()<s2.size();
	for(int i=0;i<s1.size();i++){
		if(s1[i]<s2[i]) return true;
	}
	return false;
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	string s;
	for(int i=0;i<n;i++){
		cin>>a[i];
		s=toBin(a[i]);
		if(count(s.begin(),s.end(),'0')!=0) A=0;
		ans=max(ans,a[i]);
	}
	if(A){
		priority_queue<int,vector<int>,less<int> > q(a,a+n);
		for(int i=0;i<m-1;i++){
			q.pop();
		}
		cout<<q.top()<<"\n";
		return 0;
	}
	int size=toBin(ans).size();
	
	if(m==1){
		cout<<ans<<"\n";
	}else{
		ans=0;
		string temp;
		int ct,cnt=0;
		string mx(n,'1');
		for(string i="0";i<mx;i=i+1){
			temp=i;
			for(;temp.size()<size-1;){
				temp="0"+temp;
			}
			ct=count(temp.begin(),temp.end(),'1');
			if(ct!=m) continue;
			else{
				int j=0;
				int tmp=(int)((1ll<<31)-1);
				for(char c:temp){
					if(c=='1'){
						tmp=tmp&a[j];
					}
					j++;
				}
				ans=max(ans,tmp);
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
