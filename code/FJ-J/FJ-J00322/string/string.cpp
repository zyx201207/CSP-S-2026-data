#include <bits/stdc++.h>
using namespace std;
using LL=long long;
const int maxn=2e5+10;
int n;
LL a[maxn];
LL cnt=0, half;
vector <char> str;
vector <LL> qj;
vector <LL> qj1, qj2;
vector <char> str1, str2;
LL cnt1=0, cnt2=0;
LL ans=0;
/*void cs(int _){
	cout << "----------" << _ << "-----------\n";
	return ;
}*/
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> n;
	for(int i=0;i<n;i++){
		LL x;
		char c;
		cin >> x >> c;
		a[i]=x;
		cnt+=x;
		qj.push_back(cnt);
		str.push_back(c);
	}
	half=cnt/2;
	int idex=upper_bound(qj.begin(), qj.end(), half)-qj.begin()-1;
	LL shengyu=half-qj[idex];
	for(int i=0;i<=idex;i++){
		cnt1=qj[i];
		qj1.push_back(cnt1);
		str1.push_back(str[i]);
	}
	cnt1+=shengyu;
	if(shengyu!=0)qj1.push_back(cnt1);
	if(shengyu!=0)str1.push_back(str[idex+1]);
	/*
	for(LL i:qj1)cout << i << " ";
	cout << '\n';
	for(char c:str1)cout << c << " ";
	cout << '\n';
	*/
	if(cnt%2==1)half++;
	idex++;
	for(int i=qj.size()-1;i>=idex;i--){
		cnt2+=a[i];
		qj2.push_back(cnt2);
		str2.push_back(str[i]);
	}
	shengyu=qj[idex-1]-half;
	cnt2+=shengyu;
	if(shengyu!=0)qj2.push_back(cnt2);
	if(shengyu!=0)str2.push_back(str[idex]);
	/*
	for(LL i:qj2)cout << i << " ";
	cout << '\n';
	for(char c:str2)cout << c << " ";
	cout << '\n';
	*/
	LL ok=0;
	for(LL i=0, j=0;i<qj1.size() || j<qj2.size();){
		/*if(i==131576){
			//问题出在qj1[131576] 
			cs(1);
			cout << qj1[i] << '\n';
			cs(2);
		}*/
		if(qj1[i]<=qj2[j]){
			if(str1[i]!=str2[j]){
				ans+=qj1[i]-ok;
			}
			ok=qj1[i];
			i++;
		}else if(qj1[i]>qj2[j]){
			if(str2[j]!=str1[i]){
				ans+=qj2[j]-ok;
			}
			ok=qj2[j];
			j++;
		}
	}
	
	cout << ans << '\n';
	return 0;
}

/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b



*/
