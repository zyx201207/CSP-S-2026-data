#include <iostream>
#include <vector>

using namespace std;

struct chunk{
    long long start;
    long long end;
    long long length;
    char c;
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    int n, count = 0;
    cin >> n;
    if (n == 1) {
        cout << 0 << endl;
        return 0;
    }
    vector<chunk> chunks(n);
    int a;
    char ch;
    cin >> a >> ch;
    chunks[0].start = 0;
    chunks[0].end = a - 1;
    chunks[0].c = ch;
    chunks[0].length = a;
    for (int i = 1; i < n; i++) {
        cin >> a >> chunks[i].c;
        chunks[i].start = chunks[i - 1].end + 1;
        chunks[i].end = chunks[i - 1].end + a;
        chunks[i].length = a;
    }
    int chunks_start = 0, chunks_end = n - 1;
    long long ans = 0;
    /*
    long long cnt = 0;
    long long len = s.length();
    for (long long i = 0; i < len / 2; i++){
        if (s[i] != s[len - i - 1]) cnt++;
    }
    cout << cnt << endl;
    */

    // This confirmed the theory, start impl using chunk-based diff. (left vs right diff = ans)
    // cerr << chunks_start << " " << chunks_end << endl;
    while (chunks_start < chunks_end){
        long long mlen = min(chunks[chunks_start].length, chunks[chunks_end].length);
        // cerr << chunks_start << " " << chunks_end << " " << mlen << endl;
        if(chunks[chunks_start].c != chunks[chunks_end].c){
            if(chunks[chunks_start].length == chunks[chunks_end].length){
                chunks_start++;
                chunks_end--;
                ans += mlen;
                continue;
            }
            else if (mlen == chunks[chunks_start].length){
                chunks_start++;
                chunks[chunks_end].length -= mlen;
                chunks[chunks_end].end -= mlen;
                ans += mlen;
                continue;
            }
            else{
                chunks_end--;
                chunks[chunks_start].length -= mlen;
                chunks[chunks_start].start += mlen;
                ans += mlen;
                continue;
            }
        }
        else{
            if(chunks[chunks_start].length == chunks[chunks_end].length){
                chunks_start++;
                chunks_end--;
                continue;
            }
            else if (mlen == chunks[chunks_start].length){
                chunks_start++;
                chunks[chunks_end].length -= mlen;
                chunks[chunks_end].end -= mlen;
                continue;
            }
            else{
                chunks_end--;
                chunks[chunks_start].length -= mlen;
                chunks[chunks_start].start += mlen;
                continue;
            }
        }
    }

    cout << ans << endl;

    return 0;
}