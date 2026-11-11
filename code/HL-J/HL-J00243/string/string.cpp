
int n,l,cnt = 0;
string s;
const int N = 2e5+10;
struct Node{
    int b;
    char c;
}a[N];
bool ishui(string s){
    int a = s.size();
    for(int i=0;i<a;i++){
        if(s[i]!=s[a-1-i]) return false;
    }
    return true;
}

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i].b >> a[i].c;
    }
    for(int i=1;i<=n;i++){
        l+= a[i].b;
        for(int j=1;j<=a[i].b;j++){
            s+=a[i].c;
        }
    }
    for(int i=0;i<=l;i++){
        if(ishui(s)==1){
            break;
        }
        if(s[i]!=s[l+1-i]){
            cnt++;
            s[l+1-i] = s[i];
        }
    }
    cout << cnt << endl;
    return 0;
}
