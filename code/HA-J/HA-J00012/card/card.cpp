#include <bits/stdc++.h>
using namespace std;
int check(string s,char num){
    for(int k=0;k<=s.size();k++){
        if(s[k]==num) return k;
    }
    return -1;
}


int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    long long n,m,b[100005]={0};
    char a[100005];
    string s="",test="";
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            int bmp=check(s,a[j]);
            if(bmp!=-1){
                test=s;
                s="";
                for(int k=0;k<bmp;k++){
                    s+=test[k];
                }
            }
            s += a[j];
            
        }
        //cout << s << endl;
        for(int k=0;k<s.size();k++){
            b[int(s[k])-48]++;
            //cout << int(s[k])-48 << " " << b[int(s[k])-48] << endl;
        }
        s="";
    }
    for(int i=1;i<=m;i++){
        cout << b[i]<<" ";
    }
	return 0;
}
