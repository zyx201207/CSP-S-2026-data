#incldue<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","w",stdin);
    freopen("string.ont","w",stdont);
    long long n;
    cin>>n;
    char str[2];
    cin>>str;
    int cnt=0;
    for(int i=0;i<n;i++){
        if(str==str-'1')
            break;
        else{
        if(n%2!=0)
            cnt++;
        else
            cnt++;
        }
    }
    cout<<cnt<<endl;
    return 0;
}
