//贵阳市白云区华师一学校 刘骏轩 GZ-J00038
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    int n;
    cin>>n;
    string str="";
    while(n--){
        int m;
        char ch;
        int leng=str.length();
        cin>>m>>ch;
        str.insert(leng,m,ch);
    }
    int len=str.length();
    int num=0;
    for(int i=0,j=len-1;i<len/2,j>len/2;i++,j--){
        if(str[i]!=str[j]){
            num++;
        }
    }
    cout<<num;
    return 0;
}
